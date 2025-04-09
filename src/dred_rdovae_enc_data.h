/* Auto generated from checkpoint revq7_e10_mq.pth */


#ifndef DRED_RDOVAE_ENC_DATA_H
#define DRED_RDOVAE_ENC_DATA_H

#include "nnet.h"


#include "opus_types.h"

#include "dred_rdovae_constants.h"
#include "dred_rdovae.h"

#define ENC_DENSE1_OUT_SIZE 256

#define ENC_DENSE3_OUT_SIZE 256

#define ENC_DENSE5_OUT_SIZE 256

#define ENC_DENSE7_OUT_SIZE 256

#define ENC_DENSE8_OUT_SIZE 256

#define GDENSE1_OUT_SIZE 128

#define GDENSE2_OUT_SIZE 24

#define ENC_DENSE2_OUT_SIZE 256

#define ENC_DENSE2_STATE_SIZE 256

#define ENC_DENSE4_OUT_SIZE 256

#define ENC_DENSE4_STATE_SIZE 256

#define ENC_DENSE6_OUT_SIZE 256

#define ENC_DENSE6_STATE_SIZE 256

#define BITS_DENSE_OUT_SIZE 80

#define BITS_DENSE_STATE_SIZE (2048 * (3))

#define BITS_DENSE_DELAY 1

struct RDOVAEEnc {
    DenseLayer enc_dense1;
    DenseLayer enc_dense3;
    DenseLayer enc_dense5;
    DenseLayer enc_dense7;
    DenseLayer enc_dense8;
    DenseLayer gdense1;
    DenseLayer gdense2;
    GRULayer enc_dense2;
    GRULayer enc_dense4;
    GRULayer enc_dense6;
    Conv1DLayer bits_dense;
};

int init_rdovaeenc(RDOVAEEnc *model, const WeightArray *arrays);

#endif /* DRED_RDOVAE_ENC_DATA_H */
