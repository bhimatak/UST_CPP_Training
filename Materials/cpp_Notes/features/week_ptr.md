
---

## 🧠 Use Case (Extended): **Publisher–Subscriber with Non-Owning References**

### 🎯 Goal:

* `Publisher` owns the `Article` via `shared_ptr`.
* `Subscriber` uses a **`weak_ptr`** to reference the `Article` — meaning:

  * Subscriber does **not extend** the article's lifetime.
  * If the article is deleted, `Subscriber` knows and won’t access a dangling pointer.

---

## ✅ Code Demonstration Using `weak_ptr`

```cpp
#include <iostream>
#include <memory>
#include <vector>
#include <string>

using namespace std;

// Article class represents the content
class Article {
    string content;

public:
    Article(const string& text) : content(text) {
        cout << "[Article Created]: " << content << endl;
    }

    void read() const {
        cout << "Reading Article: " << content << endl;
    }

    ~Article() {
        cout << "[Article Deleted]: " << content << endl;
    }
};

// Subscriber keeps a weak_ptr, so it does not prolong Article's life
class Subscriber {
    weak_ptr<Article> weak_article;

public:
    Subscriber(weak_ptr<Article> w) : weak_article(w) {
        cout << "[Subscriber Created]" << endl;
    }

    void readArticle() const {
        // Try to lock the weak_ptr to get a shared_ptr
        shared_ptr<Article> article = weak_article.lock();

        if (article)
            article->read();
        else
            cout << "Article no longer available!" << endl;
    }

    ~Subscriber() {
        cout << "[Subscriber Deleted]" << endl;
    }
};

int main() {
    // Outer scope for article
    shared_ptr<Article> article = make_shared<Article>("Tech Alert: Smart Pointers Explained!");

    // Subscribers reference the article but don't own it
    Subscriber s1(article);
    Subscriber s2(article);
    Subscriber s3(article);

    cout << "Initial reads by subscribers:\n";
    s1.readArticle();
    s2.readArticle();
    s3.readArticle();

    cout << "Use count (shared_ptr): " << article.use_count() << endl;

    // Destroy the article explicitly
    article.reset();  // Article deleted here

    cout << "\nAfter article is deleted:\n";
    s1.readArticle();
    s2.readArticle();
    s3.readArticle();

    return 0;
}
```

---

### 🧪 Sample Output:

```
[Article Created]: Tech Alert: Smart Pointers Explained!
[Subscriber Created]
[Subscriber Created]
[Subscriber Created]
Initial reads by subscribers:
Reading Article: Tech Alert: Smart Pointers Explained!
Reading Article: Tech Alert: Smart Pointers Explained!
Reading Article: Tech Alert: Smart Pointers Explained!
Use count (shared_ptr): 1

[Article Deleted]: Tech Alert: Smart Pointers Explained!

After article is deleted:
Article no longer available!
Article no longer available!
Article no longer available!
[Subscriber Deleted]
[Subscriber Deleted]
[Subscriber Deleted]
```

---

### 🔍 Key Concepts Illustrated:

| Concept             | Description                                                                    |
| ------------------- | ------------------------------------------------------------------------------ |
| `weak_ptr` usage    | Does not increase reference count; only observes the resource                  |
| `.lock()`           | Used to safely access the resource; returns a `shared_ptr` if alive            |
| Lifetime management | Subscribers don't keep the article alive — when publisher resets, it’s deleted |
| Safety              | Prevents dangling pointer dereference; `weak_ptr` detects expiry               |

---

## 🔄 Summary: When to Use `weak_ptr`

| Scenario                           | Should You Use `weak_ptr`? |
| ---------------------------------- | -------------------------- |
| You want to avoid circular refs    | ✅ Yes                      |
| You don't need ownership           | ✅ Yes                      |
| You want optional/temporary access | ✅ Yes                      |
| You must manage object lifetime    | ❌ No — use `shared_ptr`    |

---
