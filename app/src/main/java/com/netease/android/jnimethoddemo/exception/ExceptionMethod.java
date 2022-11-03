package com.netease.android.jnimethoddemo.exception;

import android.util.Log;

/**
 * Created by linjunyi02 on 2022/11/3
 */
public class ExceptionMethod {
    private static final String TAG = ExceptionMethod.class.getSimpleName();

    public static native void tryCatchJavaException() throws JNIException;

    public static native void throwJNIException() throws JNIException;

    public static void throwExceptionTest() {
        int a = 10 / 0;
    }

    public static void handlerExceptionFinish() {
        Log.d(TAG, "handlerExceptionFinish");
    }
}
