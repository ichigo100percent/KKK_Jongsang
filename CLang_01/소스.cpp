#include <iostream>
#include "CLang_01.h"

int main()
{
    {
        Queue queue1;
        Queue queue(100);
        queue.Enqueue(9);
        queue.Enqueue(6);
        queue.Enqueue(5);
        queue.Enqueue(3);
        queue.Display();
        
        // 복사생성자 호출
        Queue queueCopy(queue);

        queueCopy.Enqueue(20);

        std::cout << "Hello World!\n";
    }
    std::cout << "Hello World!\n";
}