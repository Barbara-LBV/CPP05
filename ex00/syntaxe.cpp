#include <stdexcept>

void test1()
{
    //do stuff here
    if (/*theres an error*/)
    {
        throw std::exception();
    }
    else
    {
        //do some more stuff
    }
}

void test2()
{
    ///do stuff here
    if (/*there's an error*/)
    {
        throw std::exception();
    }
    else
    {
        //do some stuff
    }
}

void test3()
{
    try
    {
        {
            test2();
        }
    }
    catch(const std::exception &e)
    {
        //handle error
        //std::cerr << e.what() << std::endl;
    }
    
}

void test4()
{
    class PEBKACEException : public std::exception
    {
        public:
            virtual const char * what() const throw ()
            {
                return("prob exists btw etc");
            }
    };

    try
    {
        test3();
    }
    catch(const std::exception& e)
    {
        //handle error
        //std::cerr << e.what() << '\n';
    }
    

}