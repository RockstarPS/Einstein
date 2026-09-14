#ifndef __JSON_H__
#define __JSON_H__

#ifdef __cplusplus
extern "C" {
#endif

#define SYSTEM_PATH_BIN_DOSFS "/sbin/mkdosfs"
#define SYSTEM_PATH_BIN_EXT4FS "/sbin/mkqnx6fs"

// Define dummy types
typedef struct json_object json_object;
typedef int json_type;

// Provide dummy enum if needed
enum json_type {
    json_type_null,
    json_type_boolean,
    json_type_double,
    json_type_int,
    json_type_object,
    json_type_array,
    json_type_string
};


// Dummy function to simulate json-c APIs

// Parse JSON from file
json_object* json_object_from_file(const char *filename);

// Get string from json object
const char* json_object_get_string(json_object *obj);

// Get int from json object
int json_object_get_int(json_object *obj);


#if 0
// Iterator macro — just mock it as a regular for loop in your test
#define json_object_object_foreach(obj, key, val) \
    for (int _i = 0; _i < 1; _i++) \
        for ( char *key = "fs_type", *val_key = key; val_key; val_key = 0) \
            for (json_object *val = (json_object*)0x1; val; val = 0)

#endif

#define json_object_object_foreach(obj, key, val)                        \
    for (int _j = 0; _j < 6; ++_j)                                             \
        for (char *key =                                                      \
                 (_j == 0 ? "dev" :                                            \
                  _j == 1 ? "fs_type" :                                        \
                  _j == 2 ? "mount" :                                          \
                  _j == 3 ? "recovery" :                                       \
                  _j == 4 ? "option" :                                         \
                            "unknown"),                                        \
             *val_key = key; val_key; val_key = 0)                             \
            for (json_object *val = (json_object*)0x1; val; val = 0)



#ifdef __cplusplus
}
#endif

#endif // __JSON_H__
