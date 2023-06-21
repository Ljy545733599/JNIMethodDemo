package com.netease.android.jnimethoddemo;

import android.util.Log;

public class Book {
    private static final String TAG = Book.class.getSimpleName();
    private String name;
    private int price;

    public Book(String name, int price) {
        this.name = name;
        this.price = price;
    }

    public String getName() {
        return name;
    }

    public Book setName(String name) {
        this.name = name;
        return this;
    }

    public int getPrice() {
        return price;
    }

    public Book setPrice(int price) {
        this.price = price;
        return this;
    }

    public void printInfo() {
        Log.d(TAG, "printInfo: " + "Book{" +
                "name='" + name + '\'' +
                ", price=" + price +
                '}');
    }
}
