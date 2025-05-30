/*This file is automatically generated from a Keras model*/

#ifndef PLC_DATA_H
#define PLC_DATA_H

#include "nnet.h"

#define PLC_DENSE1_OUT_SIZE 128
extern const DenseLayer plc_dense1;

#define PLC_GRU1_OUT_SIZE 256
#define PLC_GRU1_STATE_SIZE 256
extern const GRULayer plc_gru1;

#define PLC_GRU2_OUT_SIZE 256
#define PLC_GRU2_STATE_SIZE 256
extern const GRULayer plc_gru2;

#define PLC_OUT_OUT_SIZE 20
extern const DenseLayer plc_out;

#define PLC_MAX_RNN_NEURONS 256

typedef struct {
  float plc_gru1_state[PLC_GRU1_STATE_SIZE];
  float plc_gru2_state[PLC_GRU2_STATE_SIZE];
} PLCNetState;

typedef struct {
  DenseLayer plc_dense1;
  GRULayer plc_gru1;
  GRULayer plc_gru2;
  DenseLayer plc_out;
} PLCModel;

int init_plc_model(PLCModel *model, const WeightArray *arrays);



#endif
