#include <iostream>
#include <optional>
#include <functional>
#include <algorithm>


struct TreeNode {
    const uint64_t num;
    std::unique_ptr<TreeNode> left;
    std::unique_ptr<TreeNode> right;
};

std::pair<uint64_t, std::optional<uint64_t>> factor(const uint64_t n) {
    for (uint64_t left = 2; left < n / 2; left++) {
        if (n % left == 0) {
            return {left, n / left};
        }
    }
    return {n, std::nullopt}; // n is prime
}

void prime_factor(const uint64_t n, TreeNode *node) {
    auto pair = factor(n);
    node->left.reset(new TreeNode{pair.first});
    if (pair.second) { // if left is not prime
        prime_factor(node->left->num, node->left.get());
    }
    if (pair.second) {
        node->right.reset(new TreeNode{*pair.second});
        prime_factor(node->right->num, node->right.get());
    }
}

TreeNode prime_factor(const uint64_t n) {
    TreeNode root = {n};
    prime_factor(n, &root);
    return root;
}

void for_each_leaf(TreeNode *node, std::function<void(uint64_t)> const &func) {
    if (!node) return;
    if (!node->right){ // leaf if no right number
        func(node->num);
        return;
    }

    if (node->left) {
        for_each_leaf(node->left.get(), func);
    }

    if (node->right) {
        for_each_leaf(node->right.get(), func);
    }
}

int main() {
    TreeNode root = prime_factor(600851475143);

    std::vector<uint64_t> vec;
    for_each_leaf(&root, [&vec](uint64_t leaf){ vec.push_back(leaf); });


    std::cout << *std::max_element(vec.begin(), vec.end()) << std::endl;
    return 0;
}