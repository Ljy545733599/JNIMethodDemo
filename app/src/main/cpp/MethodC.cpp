//
// Created by linjunyi02 on 2022/6/30.
//

#include <jni.h>
#include <string>

namespace jnidemo {
    extern "C" {
    jstring helloWorldC(JNIEnv *env, jclass clazz) {
        return env->NewStringUTF("helloWorldC");
    }

    jint register_android_method_c(JNIEnv *env) {
        jclass clazz = env->FindClass("com/netease/android/jnimethoddemo/MethodC");
        if (clazz == nullptr) {
            return JNI_ERR;
        }
        JNINativeMethod methods[] = {
                {"helloWorldC", "()Ljava/lang/String;", (void *) helloWorldC},
        };


        return env->RegisterNatives(clazz, methods,
                                    sizeof(methods) /
                                    sizeof(methods[0]));
    }
    }
}

