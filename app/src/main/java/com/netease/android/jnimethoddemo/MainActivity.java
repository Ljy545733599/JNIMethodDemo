package com.netease.android.jnimethoddemo;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.TextView;

import com.netease.android.jnimethoddemo.databinding.ActivityMainBinding;
import com.netease.android.jnimethoddemo.exception.ExceptionMethod;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'jnimethoddemo' library on application startup.
    static {
        System.loadLibrary("jnimethoddemo");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        //动态注册，方法调用
        MethodA.helloWorldA();
        MethodB.helloWorldB();
        MethodC.helloWorldC();

        //异常处理
        try {
            ExceptionMethod.tryCatchJavaException();
        } catch (Exception e) {
            e.printStackTrace();
        }

        //异常处理
        try {
            ExceptionMethod.throwJNIException();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }


}