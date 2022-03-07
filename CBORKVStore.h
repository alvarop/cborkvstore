#pragma once

#include "cbor.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    vCBORKVStoreOK = 0,
    vCBORKVStoreERR
} CBORKVStoreErr_t;

typedef struct {
    uint8_t *buff;
    size_t buffLen;
    size_t storeLen;
    CborParser parser;
    CborEncoder encoder;
    CborEncoder mapEncoder;
} CBORKVStore_t;

CBORKVStoreErr_t cborKVStoreInit(CBORKVStore_t *store, uint8_t *buff, size_t len);

CBORKVStoreErr_t cborKVStoreGetType(CBORKVStore_t *store, CborType *type);

CBORKVStoreErr_t cborKVStoreGetUInt(CBORKVStore_t *store, const char* key, uint64_t *val);
CBORKVStoreErr_t cborKVStoreGetInt(CBORKVStore_t *store, const char* key, int64_t *val);
CBORKVStoreErr_t cborKVStoreGetBool(CBORKVStore_t *store, const char* key, bool *val);
CBORKVStoreErr_t cborKVStoreGetBuff(CBORKVStore_t *store, const char* key, uint8_t *buff, size_t *len);
CBORKVStoreErr_t cborKVStoreGetStr(CBORKVStore_t *store, const char* key, char *str, size_t *len);
CBORKVStoreErr_t cborKVStoreGetFloat(CBORKVStore_t *store, const char* key, float *val);

CBORKVStoreErr_t cborKVStoreSetUInt(CBORKVStore_t *store, const char* key, uint64_t val);
CBORKVStoreErr_t cborKVStoreSetInt(CBORKVStore_t *store, const char* key, int64_t val);
CBORKVStoreErr_t cborKVStoreSetBool(CBORKVStore_t *store, const char* key, bool val);
CBORKVStoreErr_t cborKVStoreSetBuff(CBORKVStore_t *store, const char* key, uint8_t *buff, size_t *len);
CBORKVStoreErr_t cborKVStoreSetStr(CBORKVStore_t *store, const char* key, char *str, size_t *len);
CBORKVStoreErr_t cborKVStoreSetFloat(CBORKVStore_t *store, const char* key, float val);

#ifdef __cplusplus
}
#endif
