//
// Created by linjunyi on 2022/7/6.
//

#include <jni.h>
#include "ExceptionHelper.h"

namespace jnidemo {
    /* static */
    void ExceptionHelper::throwJNIException(JNIEnv *env, const std::string &error) {
        jclass newExcCls = env->FindClass(
                "com/netease/android/jnimethoddemo/exception/JNIException");
        if (newExcCls == nullptr) {
            return;
        }

        env->ThrowNew(newExcCls, error.c_str());
    }

    /* static */
    bool ExceptionHelper::hasException(JNIEnv *env) {
        jthrowable exception = env->ExceptionOccurred();
        if (exception) {
            env->ExceptionClear();
            return true;
        }

        return false;
    }
}
