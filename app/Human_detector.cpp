/**
 * @file Human_detector.hpp
 * @author Harika Pendli (hpendli@umd.edu) and Shailesh Pranav Rajendran
 * (spraj@umd.edu)
 * @brief Driver class for all classes
 * @version 0.1
 * @date 2022-10-18
 *
 * @copyright MIT License (c) 2022 Shailesh Pranav Rajendran and Harika Pendli
 *
 */

#include "../include/Human_detector.hpp"

/**
 * @brief Constructor for Human Detector class
 *
 */
HumanDetector::HumanDetector() {
  inputHeight = 640;
  inputWidth = 640;
  nmsThreshold = 0.4;
  confidenceThreshold = 0.75;
}

void HumanDetector::drawBox(int classId, float conf, int left, int top,
                            int right, int bottom, cv::Mat& frame,
                            const std::vector<std::string> &classes,
                            unsigned int pid,
                            float z) {
  if (classId == 0) {
    // Draw a rectangle displaying the bounding box
    rectangle(frame, cv::Point(left, top), cv::Point(right, bottom),
              cv::Scalar(255, 178, 50), 3);

    // Get the label for the class name and its confidence
    std::string label = cv::format("%.2f", conf);
    if (!classes.empty()) {
      CV_Assert(classId < static_cast<int>(classes.size()));
      label = "Distance: " + std::to_string(z) + " ID:" + std::to_string(pid);
    }

    // Display the label at the top of the bounding box
    int baseLine;
    cv::Size labelSize =
        getTextSize(label, cv::FONT_HERSHEY_SIMPLEX, 0.5, 1, &baseLine);
    top = std::max(top, labelSize.height);
    rectangle(frame, cv::Point(left, top - round(1.5 * labelSize.height)),
              cv::Point(left + round(1.5 * labelSize.width), top + baseLine),
              cv::Scalar(255, 255, 255), cv::FILLED);
    putText(frame, label, cv::Point(left, top), cv::FONT_HERSHEY_SIMPLEX, 0.75,
            cv::Scalar(0, 0, 0), 1);
  }
}

std::vector<std::string> HumanDetector::getOutputsNames(
    const cv::dnn::Net& net) {
  static std::vector<std::string> names;
  if (names.empty()) {
    // Get the indices of the output layers, i.e. the layers with unconnected
    // outputs
    std::vector<int> outLayers = net.getUnconnectedOutLayers();

    // get the names of all the layers in the network
    std::vector<std::string> layersNames = net.getLayerNames();

    // Get the names of the output layers in names
    names.resize(outLayers.size());
    for (size_t i = 0; i < outLayers.size(); ++i)
      names[i] = layersNames[outLayers[i] - 1];
  }
  return names;
}

void HumanDetector::rmOverlap(cv::Mat& frame, const std::vector<cv::Mat>& outs,
                              const std::vector<std::string>& classes) {
  std::vector<int> classIds;
  std::vector<float> confidences;
  std::vector<cv::Rect> boxes;
  Transform transform;

  for (size_t i = 0; i < outs.size(); ++i) {
    // Scan through all the bounding boxes output from the network and keep only
    // the ones with high confidence scores. Assign the box's class label as the
    // class with the highest score for the box.
    float* data = reinterpret_cast<float*>(outs[i].data);
    for (int j = 0; j < outs[i].rows; ++j, data += outs[i].cols) {
      cv::Mat scores = outs[i].row(j).colRange(5, outs[i].cols);
      cv::Point classIdPoint;
      double confidence;
      // Get the value and location of the maximum score
      minMaxLoc(scores, 0, &confidence, 0, &classIdPoint);
      if (confidence > confidenceThreshold) {
        int centerX = static_cast<int>(data[0] * frame.cols);
        int centerY = static_cast<int>(data[1] * frame.rows);
        int width = static_cast<int>(data[2] * frame.cols);
        int height = static_cast<int>(data[3] * frame.rows);
        int left = centerX - width / 2;
        int top = centerY - height / 2;

        classIds.push_back(classIdPoint.x);
        confidences.push_back(static_cast<float>(confidence));
        boxes.push_back(cv::Rect(left, top, width, height));
      }
    }
  }

  // Perform non maximum suppression to eliminate redundant overlapping boxes
  // with lower confidences
  std::vector<int> indices;
  cv::dnn::NMSBoxes(boxes, confidences, confidenceThreshold, nmsThreshold,
                    indices);
  unsigned int personid = 1;
  for (auto idx : indices) {
    cv::Rect box = boxes[idx];
    float z_axis = transform.calculate_distance(box.height, frame.rows);
    drawBox(classIds[idx], confidences[idx], box.x, box.y, box.x + box.width,
            box.y + box.height, frame, classes, personid, z_axis);
    transform.camera_robot_array(z_axis, box, frame);
    std::cout << "Distance from person " << personid
      << " is: " << z_axis << "m" << std::endl;
    personid++;
  }
}

void HumanDetector::detect(cv::CommandLineParser parser) {
  std::vector<std::string> classes;

  ModelConfig yolov3;
  DataReader input;
  classes = yolov3.getClasses();

  cv::dnn::Net net =
      cv::dnn::readNetFromDarknet(yolov3.getConfig(), yolov3.getWeights());
  net.setPreferableBackend(cv::dnn::DNN_BACKEND_OPENCV);
  net.setPreferableTarget(cv::dnn::DNN_TARGET_CPU);

  cv::VideoCapture cap;
  cv::VideoWriter video;
  cv::Mat frame, blob;

  try {
    std::string input_Type = "";
    std::string inputPath = input.getInput(parser, input_Type);
    if (input_Type == "image") {
      input.setImagepath(inputPath);
      cap = input.imgProcessor('r', frame);
    }
    if (input_Type == "video") {
      input.setVideopath(inputPath);
      cap = input.videoProcessor('r', frame, video);
      input.setOutputWidth(cap.get(cv::CAP_PROP_FRAME_WIDTH));
      input.setOutputHeight(cap.get(cv::CAP_PROP_FRAME_HEIGHT));
      video.open(
          "../output/Result.mp4", cv::VideoWriter::fourcc('a', 'v', 'c', '1'),
          24, cv::Size(input.getOutputWidth(), input.getOutputHeight()), true);
    }
  } catch (...) {
    std::cout << "Could not open the input image/video stream" << std::endl;
  }

  while (cv::waitKey(1) < 0) {
    cap >> frame;

    // Stop the program if reached end of video
    if (frame.empty()) {
      std::cout << "Detection Completed" << std::endl;
      std::cout << "Output file is stored in Output Folder" << std::endl;
      cv::waitKey(3000);
      break;
    }
    // Create a 4D blob from a frame.
    cv::dnn::blobFromImage(frame, blob, 1 / 255.0,
                           cv::Size(inputWidth, inputHeight),
                           cv::Scalar(0, 0, 0), true, false);

    // Sets the input to the network
    net.setInput(blob);

    // Runs the forward pass to get output of the output layers
    std::vector<cv::Mat> outs;
    net.forward(outs, getOutputsNames(net));

    // Remove the bounding boxes with low confidence
    rmOverlap(frame, outs, classes);

    // Put efficiency information.
    std::vector<double> layersTimes;
    double freq = cv::getTickFrequency() / 1000;

    // The function getPerfProfile returns the overall time for inference(t)
    // and the timings for each of the layers(in layersTimes)
    double t = net.getPerfProfile(layersTimes) / freq;
    std::string label = cv::format("Inference time for a frame : %.2f ms", t);
    putText(frame, label, cv::Point(0, 15), cv::FONT_HERSHEY_SIMPLEX, 0.5,
            cv::Scalar(0, 0, 255));

    // Write the frame with the detection boxes
    cv::Mat detectedFrame;
    frame.convertTo(detectedFrame, CV_8U);
    if (parser.has("image"))
      input.imgProcessor('w', detectedFrame);
    else
      input.videoProcessor('w', detectedFrame, video);

    if(!parse.has("hide_output")){
      static const std::string Window_name = " Human detection";
      namedWindow(Window_name, cv::WINDOW_NORMAL);
      imshow(Window_name, frame);
      if (parser.has("image")) {
        cv::waitKey(3000);
      }
    }
  }

  cap.release();
  if (parser.has("video")) video.release();
}
