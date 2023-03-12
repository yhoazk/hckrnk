#include <bits/stdc++.h>


namespace bintree {

struct bintree {
    int data{};
    bintree* left{nullptr};
    bintree* right{nullptr};
};

// template<typename T>
bool insert(bintree* bt, int val) {
    if (val > bt->data) {
        // add to right
        if (bt->right == nullptr) {
            bt->right =  new bintree{ .data = val, .left = nullptr, .right = nullptr};
        } else {
            insert(bt->right, val);
        }
    } else {
        //  add to the left
        if (bt->left == nullptr) {
            bt->left =  new bintree{ .data = val, .left = nullptr, .right = nullptr};
        } else {
            insert(bt->left, val);
        }
    }
    return true;
}

void show(const bintree* bt, int level=0) {
    if(level) { std::cerr << std::setw(level) << ' ';}
    std::cout << bt->data << std::endl;
    if(bt->left != nullptr) {
        std::cerr << "L: ";
        show(bt->left, level+4);
    }
    if(bt->right != nullptr) {
        std::cerr << "R: ";
        show(bt->right, level+4);
    }
}

void preorder(const bintree* bt) {
    if (bt == nullptr){
        return;
    }
    std::cerr << bt->data << "-";
    preorder(bt->left);
    preorder(bt->right);
}

bintree* find(bintree* bt, int val) {
    if (bt == nullptr) {
        return nullptr;
    }

    if (bt->data == val) {
        return bt;
    } else if (val > bt->data ) {
        //
        find(bt->right, val);
    } else {
        //
        find(bt->left, val);
    }
    return nullptr;
}

size_t max_len_r(bintree* bt) {
    if (bt == nullptr) {
        return 0;
    } else {
        
    }


    return std::max( max_len_r(bt->left)+1, 1+ max_len_r(bt->right));
    // auto lh {max_len(bt->left)};
    // auto rh { max_len(bt->right)};

    // return std::max(lh+1, rh+1);
}


size_t max_len(bintree* bt) {
    return max_len_r(bt) -1l;
}


} // namespace bintree

int main () {
    bintree::bintree root{.data=24, .left=nullptr, .right=nullptr};
    insert(&root, 15);
    insert(&root, 30);
    insert(&root, 7);
    insert(&root, 17);
    insert(&root, 16);
    insert(&root, 19);
    insert(&root, 35);
    insert(&root, 70);
    insert(&root, 90);
    insert(&root, 65);
    insert(&root, 68);
    show(&root);
    preorder(&root);
    std::cerr << std::endl;

    if (nullptr != bintree::find(&root, 12)) {
        std::cerr << "12 is in bt" << std::endl;
    } else {
        std::cerr << "12 not in bt" << std::endl;
    }

    if (nullptr != bintree::find(&root, 92)) {
        std::cerr << "92 is in bt" << std::endl;
    } else {
        std::cerr << "92 not in bt" << std::endl;
    }

    std::cerr << "Max len: " << bintree::max_len(&root) << std::endl;
    return 0;
}