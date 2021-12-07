#include "Control.hpp"
#include "UserControl.hpp"
#include <cctype>
#include "Model.hpp"
#include "TestModel.hpp"

class UserControl::public Control()
{
    Model *model = new TestModel();
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