auto func(auto a, auto b){
    return a + b;
}

int main (){
    int x = 3;
    float y = 5;
    long z = 6;
    auto res1 = func(x, x);
    auto res2 = func(x, y);
    auto res3 = func(y, z); // all works, function deduced to different templates each time
    return 0;
}