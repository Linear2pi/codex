#pragma once

struct VitalSample {
  unsigned long ts;
  int heartRate;
  int respRate;
  int presence;
  float confidence;
};
