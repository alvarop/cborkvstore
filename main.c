#include <stdio.h>
#include <stdlib.h>
#include "tinycbor/src/cbor.h"

static const uint8_t byteStr[] = {0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF};

int main(int argc, char* argv[]) {
  (void)argc;
  (void)argv;

  printf("CBOR Test!\n");

  uint8_t buff[1024];
  CborError err = CborNoError;
  CborEncoder encoder, mapEncoder;

  do {
    cbor_encoder_init(&encoder, buff, sizeof(buff), 0);

    err = cbor_encoder_create_map(&encoder, &mapEncoder, CborIndefiniteLength);
    if(err) {
      break;
    }

    err = cbor_encode_text_stringz(&mapEncoder, "KEEEEYYYY");
    if(err) {
      break;
    }


    err = cbor_encode_text_stringz(&mapEncoder, "stringval");
    if(err) {
      break;
    }

    err = cbor_encode_text_stringz(&mapEncoder, "Dat2");
    if(err) {
      break;
    }

    err = cbor_encode_byte_string(&mapEncoder, byteStr, sizeof(byteStr));
    if(err) {
      break;
    }

    err = cbor_encode_text_stringz(&mapEncoder, "boolval");
    if(err) {
      break;
    }

    err = cbor_encode_boolean(&mapEncoder, 0);
    if(err) {
      break;
    }

    err = cbor_encode_text_stringz(&mapEncoder, "number");
    if(err) {
      break;
    }

    err = cbor_encode_uint(&mapEncoder, 12);
    if(err) {
      break;
    }

    err = cbor_encode_text_stringz(&mapEncoder, "number2");
    if(err) {
      break;
    }

    err = cbor_encode_uint(&mapEncoder, 129);
    if(err) {
      break;
    }

    err = cbor_encode_text_stringz(&mapEncoder, "number3");
    if(err) {
      break;
    }

    err = cbor_encode_uint(&mapEncoder, 32769);
    if(err) {
      break;
    }

    err = cbor_encode_text_stringz(&mapEncoder, "flooooat");
    if(err) {
      break;
    }

    err = cbor_encode_float(&mapEncoder, 1234.56);
    if(err) {
      break;
    }

    err = cbor_encoder_close_container(&encoder, &mapEncoder);
    if(err) {
      break;
    }


    size_t len = cbor_encoder_get_buffer_size(&encoder, buff);
    for(uint32_t byte=0; byte < len; byte++) {
      printf("%02X ", buff[byte]);
    }
    printf("\n");
  } while (0);

  if(err) {
    printf("Error! %s\n", cbor_error_string(err));
  }

  return 0;
}
