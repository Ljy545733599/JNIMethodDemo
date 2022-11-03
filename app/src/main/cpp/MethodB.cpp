//
// Created by linjunyi02 on 2022/6/30.
//

#include <jni.h>
#include <string>

namespace jnidemo {
    extern "C" {
    jstring helloWorldB(JNIEnv *env, jclass clazz) {
        return env->NewStringUTF("helloWorldC");
    }

    jint register_android_method_b(JNIEnv *env) {
        jclass clazz = env->FindClass("com/netease/android/jnimethoddemo/MethodB");
        if (clazz == nullptr) {
            return JNI_ERR;
        }
        JNINativeMethod methods[] = {
                {"helloWorldB", "()Ljava/lang/String;", (void *) helloWorldB},
        };


        return env->RegisterNatives(clazz, methods,
                                    sizeof(methods) /
                                    sizeof(methods[0]));
    }
    }
}
