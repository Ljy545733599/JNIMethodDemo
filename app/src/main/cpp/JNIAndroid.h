//
// Created by linjunyi02 on 2023/6/19.
//
#ifndef JNIMETHODDEMO_JNI_ANDROID_H
#define JNIMETHODDEMO_JNI_ANDROID_H

#include <jni.h>

namespace jnidemo {
    JNIEnv *AttachCurrentThread();

    void DetachFromVM();

    void InitVM(JavaVM *vm);

    bool IsVMInitialized();

}   //namespace jnidemo

#endif //JNIMETHODDEMO_JNI_ANDROID_H