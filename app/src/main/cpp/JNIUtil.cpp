//
// Created by linjunyi on 2022/7/18.
//

#include "JNIUtil.h"

namespace jnidemo {
    /* static */
    jstring JNIUtil::charToJString(JNIEnv *env, char *pat) {
        //定义java String类 strClass
        jclass strClass = (env)->FindClass("java/lang/String");
        //获取java String类方法String(byte[],String)的构造器,用于将本地byte[]数组转换为一个新String
        jmethodID ctorID = (env)->GetMethodID(strClass, "<init>", "([BLjava/lang/String;)V");
        //建立byte数组
        jbyteArray bytes = (env)->NewByteArray((jsize) strlen(pat));
        //将char* 转换为byte数组
        (env)->SetByteArrayRegion(bytes, 0, (jsize) strlen(pat), (jbyte *) pat);
        //设置String, 保存语言类型,用于byte数组转换至String时的参数
        jstring encoding = (env)->NewStringUTF("UTF-8");
        //将byte数组转换为java String,并输出
        return (jstring) (env)->NewObject(strClass, ctorID, bytes, encoding);
    }

    /* static */
    char *JNIUtil::jstringToChar(JNIEnv *env, jstring jstr) {
        char *rtn = nullptr;
        jclass clsstring = env->FindClass("java/lang/String");
        jstring strencode = env->NewStringUTF("UTF-8");
        jmethodID mid = env->GetMethodID(clsstring, "getBytes", "(Ljava/lang/String;)[B");
        auto barr = (jbyteArray) env->CallObjectMethod(jstr, mid, strencode);
        jsize alen = env->GetArrayLength(barr);
        jbyte *ba = env->GetByteArrayElements(barr, JNI_FALSE);
        if (alen > 0) {
            rtn = (char *) malloc(alen + 1);
            memcpy(rtn, ba, alen);
            rtn[alen] = 0;
        }
        env->ReleaseByteArrayElements(barr, ba, 0);
        return rtn;
    }

    /* static */
    std::string JNIUtil::jbyteArrayToString(JNIEnv *env, jbyteArray bytes) {
        int chars_len = env->GetArrayLength(bytes);
        std::string result;
        result.assign((char *) env->GetByteArrayElements(bytes, JNI_FALSE), chars_len);
        return result;
    }

}