/*
 * Copyright (c) 2015 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */

package com.qualcomm.qti.sva.ux.user;

import com.qualcomm.qti.sva.R;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.RelativeLayout;
import android.widget.TextView;

public class Tutorial4Activity extends Activity {
    private final static String TAG = "ListenLog.Tutorial4Activity";

    // UI Elements.
    private RelativeLayout uiRlBottomBar;
    private TextView uiTvNext;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        Log.v(TAG, "onCreate");

        setContentView(R.layout.activity_user_tutorial4);

        uiRlBottomBar = (RelativeLayout) findViewById(R.id.user_tutorial4_bottombar);
        uiTvNext = (TextView) uiRlBottomBar.findViewById(R.id.bottombar_tv_next);
        uiTvNext.setText(R.string.done);
    }

    public void BackOrNextClicked(View view) {
        Log.v(TAG, "BackOrNextClicked");
        if (view.getId() == R.id.bottombar_tv_back) {
            Log.v(TAG, "BackOrNextClicked- back was clicked.");
            finish();
        } else if (view.getId() == R.id.bottombar_tv_next) {
            Log.v(TAG, "BackOrNextClicked- next was clicked.");
            Intent intent = new Intent(Tutorial4Activity.this, MainActivity.class);
            intent.setFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP | Intent.FLAG_ACTIVITY_CLEAR_TASK);
            startActivity(intent);
        } else {
            Log.e(TAG, "BackOrNextClicked- Unknown button called this function. " +
                    "Neither back nor next was clicked.");
        }
    }
}
