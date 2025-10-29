


class Rectangle
{
    protected:
        int width, height;
    public:
        Rectangle(int width, int height) : width(width), height(height) {}

        int getWidth() const{
            return width;
        }

        void setWidth(int width){
            Rectangle::width = width;
        }

        int getHeight() const{
            return height;
        }

        void setHeight(int height){
            Rectangle::height = height;
        }
};