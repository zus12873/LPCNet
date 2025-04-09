/* Auto generated from checkpoint revq7_e10_mq.pth */


#ifndef DRED_RDOVAE_DEC_DATA_H
#define DRED_RDOVAE_DEC_DATA_H

#include "nnet.h"


#include "opus_types.h"

#include "dred_rdovae_constants.h"
#include "dred_rdovae.h"

#define STATE1_OUT_SIZE 256

#define STATE2_OUT_SIZE 256

#define STATE3_OUT_SIZE 256

#define DEC_DENSE1_OUT_SIZE 256

#define DEC_DENSE3_OUT_SIZE 256

#define DEC_DENSE5_OUT_SIZE 256

#define DEC_DENSE7_OUT_SIZE 256

#define DEC_DENSE8_OUT_SIZE 256

#define DEC_FINAL_OUT_SIZE 80

#define DEC_DENSE2_OUT_SIZE 256

#define DEC_DENSE2_STATE_SIZE 256

#define DEC_DENSE4_OUT_SIZE 256

#define DEC_DENSE4_STATE_SIZE 256

#define DEC_DENSE6_OUT_SIZE 256

#define DEC_DENSE6_STATE_SIZE 256

struct RDOVAEDec {
    DenseLayer state1;
    DenseLayer state2;
    DenseLayer state3;
    DenseLayer dec_dense1;
    DenseLayer dec_dense3;
    DenseLayer dec_dense5;
    DenseLayer dec_dense7;
    DenseLayer dec_dense8;
    DenseLayer dec_final;
    GRULayer dec_dense2;
    GRULayer dec_dense4;
    GRULayer dec_dense6;
};

int init_rdovaedec(RDOVAEDec *model, const WeightArray *arrays);

#endif /* DRED_RDOVAE_DEC_DATA_H */
