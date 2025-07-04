// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>
#include <memory>

class PMTree {
 public:
    explicit PMTree(const std::vector<char>& elements);

    struct Node {
        char value;
        std::vector<std::shared_ptr<Node>> children;
        explicit Node(char val) : value(val) {}
    };
    std::shared_ptr<Node> getRoot() const { return _root; }
    size_t getAllPerm() const { return final_perm; }
 private:
    std::shared_ptr<Node> _root;
    size_t final_perm;
    void buildTree(std::shared_ptr<Node> parent,
                 const std::vector<char>& remaining_elements);
};

std::vector<std::vector<char>> getAllPerm(const PMTree& tree);
std::vector<char> getPerm1(const PMTree& tree, int num);
std::vector<char> getPerm2(const PMTree& tree, int num);
#endif  // INCLUDE_TREE_H_
