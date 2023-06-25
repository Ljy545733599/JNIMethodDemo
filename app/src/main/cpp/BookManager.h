//
// Created by linjunyi02 on 2023/6/14.
//

#ifndef JNIMETHODDEMO_BOOKMANAGER_H
#define JNIMETHODDEMO_BOOKMANAGER_H

#include <jni.h>
#include <string>
#include <vector>

namespace jnidemo {

    class BookManager {
    public:
        BookManager();

        virtual ~BookManager();

        static jlong CreateBookManager(JNIEnv *env, jclass clazz);

        static void AddBook(JNIEnv *env, jclass clazz, jlong native_ptr, jstring name, jint price);

        static void PrintBookInfoNative(JNIEnv *env, jclass clazz, jlong native_ptr);

        static void DestroyBookManager(JNIEnv *env, jclass clazz, jlong manager);

    private:
        void AddNewBook(const std::string& name, int price);

        void PrintBookInfo();

    private:
        jobject book_ = nullptr;
    };

}   //namespace jnidemo

#endif //JNIMETHODDEMO_BOOKMANAGER_H
