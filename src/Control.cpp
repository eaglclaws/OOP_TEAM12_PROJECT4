#include "Control.hpp"
#include "Model.cpp"
#include <cctype>
#include "Model.hpp"
#include "TestModel.hpp"

Model *model = new TestModel();

void init()
{

    model.init();
    model.update();
}
void command(int n)
{
    //입력받은게 int인지 판단
    //우리 기능 내에 범위 안에 있는지 확인
    //Model.command int값 넘겨줌

    if (isdigit(n))
    {
        model.command(int n);
        refresh();
    }
}
void refresh()
{
    model.update();
}

void command_str(string s)
{
    if (!isdigit(s))
    {
        model.command(s);
        refresh();
    }
}

//사용자 입력을 받고 언제 모델을 업데이트할건지 판단하고
//언제 커멘드를 넘기는지 판단하는것