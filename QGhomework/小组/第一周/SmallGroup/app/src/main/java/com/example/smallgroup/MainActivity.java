package com.example.smallgroup;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.Toast;


public class MainActivity extends AppCompatActivity implements View.OnClickListener {

   private EditText editText;
   private ImageView imageView;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Button button1 = (Button) findViewById(R.id.button1);
        editText = (EditText) findViewById(R.id.edit_text);
        imageView = (android.widget.ImageView) findViewById(R.id.imageView);
        button1.setOnClickListener(this);
    }
            @Override
            public void onClick(View v) {

                if (v.getId() == R.id.button1) {
                    String inputText = editText.getText().toString();
                    Toast.makeText(MainActivity.this, inputText, Toast.LENGTH_SHORT).show();

                }
                if (v.getId() == R.id.button2) {
                   imageView.setImageResource(R.drawable.ic_launcher_foreground);

                }
            }


    }

        /*Button button =(Button)findViewById(R.id.button2);
        button.setOnClickListener(this);
        @Override
        public void onclick(View v){
            switch(v.getId()) {
                case R.id.button2:
                    Toast.makeText(MainActivity.this, "You clicked Button", Toast.LENGTH_SHORT).show();
                default:
                    break;
            }
        }*/
