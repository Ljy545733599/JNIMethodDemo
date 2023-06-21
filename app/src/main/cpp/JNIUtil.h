//
// Created by linjunyi on 2022/7/18.
//

#ifndef DATANDROID_JNI_UTIL_H
#define DATANDROID_JNI_UTIL_H

#include <jni.h>
#include <string>

namespace jnidemo {
    class JNIUtil {
    public:
        static jstring charToJString(JNIEnv *env, char *pat);

        static char *jstringToChar(JNIEnv *env, jstring jstr);

        static std::string jbyteArrayToString(JNIEnv *env, jbyteArray bytes);
    };
}


#endif //DATANDROID_JNI_UTIL_H
