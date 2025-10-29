


class Rectangle
{
    protected:
        int width, height;
    public:
        Rectangle(int width, int height) : width(width), height(height) {}

        int getWidth() const{
            return width;
        }

        virtual void setWidth(int width){
            Rectangle::width = width;
        }

        // Const member function (accessor)
        // Can be called on both const and non-const objects.
        // The 'const' keyword after the signature ensures this function
        // does not change 'height' or 'width'.
        int getHeight() const{
            return height;
        }

        virtual void setHeight(int height){
            Rectangle::height = height;
        }
};

//This class below violates the liskov substitution principle. The process function does not work for derived classes like square(gives unexpected results)
class Square: public Rectangle
{
    public:
        Square(int size): Rectangle(size, size) {}

        void setWidth(int width) override{
            this->width  = this->height = width;
        }

        void setHeight(int height) override{
             this->width  = this->height = width;
        }
}


//use factory to solve this problem
struct RectangleFactory
{
    static Rectangle create_rectangle(int w, int h);
    static Rectangle create_square(int size);
}

void process(Rectangle& r){
    int w = r.getWidth();
    r.setHeight(10);

    std::cout << "expected area = " << (w*10) << " got " << r.area() << std::endl;
}




