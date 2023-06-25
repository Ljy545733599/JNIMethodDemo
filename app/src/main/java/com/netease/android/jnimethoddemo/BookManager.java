package com.netease.android.jnimethoddemo;

/**
 * Created by linjunyi02 on 2023/6/20
 */
public class BookManager {
    public static native long createBookManager();
    public static native void addBook(long nativeNookManager, String name, int price);
    public static native void printInfo(long nativeNookManager);
    public static native void destroy(long nativeNookManager);
}
