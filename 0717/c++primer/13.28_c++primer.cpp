#include <iostream>
#include <string>
#include <vector>
using namespace std;
class TreeNode
{
    public:
        TreeNode();
        TreeNode(const TreeNode &other);
        TreeNode &operator = (const TreeNode &other);
    private:
        std::string value_;
        int count_;
        TreeNode *left_;
        TreeNode *right_;
};
TreeNode::TreeNode():
    count_(0),
    left_(NULL),
    right_(NULL)
{}
TreeNode::TreeNode(const TreeNode &other):
    value_(other.value_),
    count_(other.count_),
    left_(new TreeNode(*other.left_)),
    right_(new TreeNode(*other.right_))
{}
TreeNode &TreeNode::operator = (const TreeNode &other)
{
    if(this != &other)
    {
        delete left_;
        delete right_;
        left_ = new TreeNode(*other.left_);
        right_ = new TreeNode(*other.right_);
        count_ = other.count_;
        value_ = other.value_;
    }
    return *this;
    
}

int main(int argc, const char *argv[])
{
    TreeNode root;
    return 0;
}
