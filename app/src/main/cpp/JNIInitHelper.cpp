#include <jni.h>
#include <string>

#include "JNIAndroid.h"

namespace jnidemo {
    extern "C" {
    //1.注册方法声明
    extern jint register_android_method_a(JNIEnv *);

    extern jint register_android_method_b(JNIEnv *);

    extern jint register_android_method_c(JNIEnv *);

    extern jint register_android_method_exception(JNIEnv *);

    extern jint register_android_book_manager(JNIEnv *);

    //2.给注册方法一个别名，方便使用
    using reg_jni_method = jint (*)(JNIEnv *env);

    //3.int 类型的函数数组
    static const reg_jni_method gRegJNI[] = {
            register_android_method_a,
            register_android_method_b,
            register_android_method_c,
            register_android_method_exception,
            register_android_book_manager
    };

    //4.遍历注册
    static jint register_jni_procs(const reg_jni_method array[], size_t count, JNIEnv *env) {
        for (size_t i = 0; i < count; i++) {
            if (array[i](env) < 0) {
                return -1;
            }
        }
        return 0;
    }

    //5.JNI_OnLoad 方法
    JNIEXPORT jint JNI_OnLoad(JavaVM *vm, void *reserved) {
        JNIEnv *env = nullptr;

        //保存当前 java vm
        InitVM(vm);
        if (vm->GetEnv((void **) &env, JNI_VERSION_1_6) != JNI_OK) {
            return JNI_ERR;
        }

        // 注册方法
        if (register_jni_procs(gRegJNI, sizeof(gRegJNI) / sizeof(gRegJNI[0]), env) < 0) {
            return -1;
        }

        return JNI_VERSION_1_6;

    }
    }
}
