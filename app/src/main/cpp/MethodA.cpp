//
// Created by linjunyi02 on 2022/6/30.
//
#include <jni.h>
#include <string>

namespace jnidemo {
    extern "C" {

    jstring helloWorldA(JNIEnv *env, jclass clazz) {
        return env->NewStringUTF("helloWorldA");
    }

    jint register_android_method_a(JNIEnv *env) {
        jclass clazz = env->FindClass("com/netease/android/jnimethoddemo/MethodA");
        if (clazz == nullptr) {
            return JNI_ERR;
        }
        JNINativeMethod methods[] = {
                {"helloWorldA", "()Ljava/lang/String;", (void *) helloWorldA},
        };


        return env->RegisterNatives(clazz, methods,
                                    sizeof(methods) /
                                    sizeof(methods[0]));
    }
    }
}

