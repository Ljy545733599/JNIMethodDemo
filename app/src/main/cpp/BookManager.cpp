//
// Created by linjunyi02 on 2023/6/14.
//

#include "BookManager.h"

#include "JNIAndroid.h"
#include "JNILog.h"
#include "JNIUtil.h"

namespace jnidemo {
    extern "C" {
    jint register_android_book_manager(JNIEnv *env) {
        jclass clazz = env->FindClass("com/netease/android/jnimethoddemo/BookManager");
        if (clazz == nullptr) {
            return JNI_ERR;
        }
        JNINativeMethod methods[] = {
                {"createBookManager", "()J",                     (void *) BookManager::CreateBookManager},
                {"addBook",           "(JLjava/lang/String;I)V", (void *) BookManager::AddBook},
        };


        return env->RegisterNatives(clazz, methods,
                                    sizeof(methods) /
                                    sizeof(methods[0]));
    }
    }

    BookManager::BookManager() {
    }

    BookManager::~BookManager() {
        JNIEnv *env = AttachCurrentThread();
        if (env == nullptr) {
            return;
        }

        if (book_ == nullptr) {
            return;
        }

        env->DeleteGlobalRef(book_);
        book_ = nullptr;
    }

    void BookManager::AddNewBook(const std::string &name, int price) {
        JNIEnv *env = AttachCurrentThread();
        if (env == nullptr) {
            return;
        }

        jclass cls_string = env->FindClass("com/netease/android/jnimethoddemo/Book");
        if (cls_string == nullptr) {
            return;
        }

        jmethodID mid = env->GetMethodID(cls_string, "<init>", "(Ljava/lang/String;I)V");
        if (mid == nullptr) {
            return;
        }


        jstring book_name = env->NewStringUTF(name.c_str());
        book_ = env->NewGlobalRef(env->NewObject(cls_string, mid, book_name, price));
        env->DeleteLocalRef(cls_string);

        PrintBookInfo();
    }

    void BookManager::PrintBookInfo() {
        if (book_ == nullptr) {
            return;
        }

        JNIEnv *env = AttachCurrentThread();
        if (env == nullptr) {
            return;
        }

        jclass cls_string = env->FindClass("com/netease/android/jnimethoddemo/Book");
        if (cls_string == nullptr) {
            return;
        }

        jmethodID mid = env->GetMethodID(cls_string, "printInfo", "()V");
        if (mid == nullptr) {
            return;
        }

        env->CallVoidMethod(book_, mid);
    }

    jlong BookManager::CreateBookManager(JNIEnv *env, jclass clazz) {
        auto *book_manager = new BookManager();
        return reinterpret_cast<jlong>(book_manager);
    }

    void BookManager::DestroyBookManager(long manager) {

    }

    void
    BookManager::AddBook(JNIEnv *env, jclass clazz, jlong native_ptr, jstring name, jint price) {
        auto *book_manager = reinterpret_cast<BookManager *>(native_ptr);
        if (book_manager == nullptr) {
            return;
        }

        char *name_char = JNIUtil::jstringToChar(env, name);
        if (name_char == nullptr) {
            return;
        }
        std::string name_str = name_char;
        book_manager->AddNewBook(name_str, price);
    }

}   //namespace jnidemo
