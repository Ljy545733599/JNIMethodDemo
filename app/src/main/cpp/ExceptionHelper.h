//
// Created by linjunyi on 2022/7/6.
//

#ifndef DATANDROID_JNI_EXCEPTION_HELPER_H
#define DATANDROID_JNI_EXCEPTION_HELPER_H

#include <string>

namespace jnidemo {
    class ExceptionHelper {
    public:
        static void throwJNIException(JNIEnv *env, const std::string &error);
        static bool hasException(JNIEnv *env);
    };
}

#endif //DATANDROID_JNI_EXCEPTION_HELPER_H
