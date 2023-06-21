//
// Created by linjunyi02 on 2023/6/19.
//

#include <jni.h>
#include <sys/prctl.h>

namespace {

    JavaVM *g_jvm = nullptr;

}

namespace jnidemo {


    JNIEnv *AttachCurrentThread() {
        JNIEnv *env = nullptr;
        jint ret = g_jvm->GetEnv(reinterpret_cast<void **>(&env), JNI_VERSION_1_2);
        if (ret == JNI_EDETACHED || !env) {
            JavaVMAttachArgs args;
            args.version = JNI_VERSION_1_2;
            args.group = nullptr;

            // 16 is the maximum size for thread names on Android.
            char thread_name[16];
            int err = prctl(PR_GET_NAME, thread_name);
            if (err < 0) {
                args.name = nullptr;
            } else {
                args.name = thread_name;
            }

            ret = g_jvm->AttachCurrentThread(&env, &args);
        }
        return env;
    }

    void DetachFromVM() {
        // Ignore the return value, if the thread is not attached, DetachCurrentThread
        // will fail. But it is ok as the native thread may never be attached.
        if (g_jvm)
            g_jvm->DetachCurrentThread();
    }

    void InitVM(JavaVM *vm) {
        g_jvm = vm;
    }

    bool IsVMInitialized() {
        return g_jvm != nullptr;
    }

}   //namespace jnidemo

