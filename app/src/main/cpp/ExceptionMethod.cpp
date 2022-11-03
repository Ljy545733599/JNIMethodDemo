//
// Created by linjunyi02 on 2022/11/3.
//

#include <jni.h>
#include <string>
#include <exception>

#include "JNILog.h"
#include "ExceptionHelper.h"

namespace jnidemo {
    extern "C" {

    void tryCatchJavaException(JNIEnv *env, jclass clazz) {
        //调用 Java 的异常代码，并进行捕获
        jclass exceptionMethodClass = env->FindClass(
                "com/netease/android/jnimethoddemo/exception/ExceptionMethod");
        jmethodID throwExceptionTest = env->GetStaticMethodID(exceptionMethodClass,
                                                              "throwExceptionTest",
                                                              "()V");
        jmethodID handlerExceptionFinish = env->GetStaticMethodID(exceptionMethodClass,
                                                              "handlerExceptionFinish",
                                                              "()V");
        env->CallStaticVoidMethod(exceptionMethodClass, throwExceptionTest);

        jthrowable exception = env->ExceptionOccurred();
        if (exception) {
            env->ExceptionClear();
            LOGD("ExceptionClear");
        }
        env->CallStaticVoidMethod(exceptionMethodClass, handlerExceptionFinish);

        LOGD("handlerExceptionFinish");
    }

    void throwJNIException(JNIEnv *env, jclass clazz) {
        LOGD("throwJNIException");
        try {
            throw "jni exception";
        } catch (const char* exception) {
            jclass newExcCls = env->FindClass(
                    "com/netease/android/jnimethoddemo/exception/JNIException");
            if (newExcCls == nullptr) {
                return;
            }

            env->ThrowNew(newExcCls, exception);
        }
    }



    jint register_android_method_exception(JNIEnv *env) {
        jclass clazz = env->FindClass(
                "com/netease/android/jnimethoddemo/exception/ExceptionMethod");
        if (clazz == nullptr) {
            return JNI_ERR;
        }
        JNINativeMethod methods[] = {
                {"tryCatchJavaException", "()V", (void *) tryCatchJavaException},
                {"throwJNIException", "()V", (void *) throwJNIException},
        };


        return env->RegisterNatives(clazz, methods,
                                    sizeof(methods) /
                                    sizeof(methods[0]));
    }
    }
}