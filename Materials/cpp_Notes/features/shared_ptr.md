
---

## 🔧 Use Case: **Publishing System** (Publisher–Subscriber)

### 🎯 Goal:

* A `Publisher` creates messages (articles/news).
* Multiple `Subscribers` can read the same message.
* Shared ownership of the message is necessary since it lives as long as at least one subscriber exists.

---

## ✅ Code Demonstration Using `shared_ptr`

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

// Subscriber reads the shared article
class Subscriber {
    shared_ptr<Article> article;

public:
    Subscriber(shared_ptr<Article> a) : article(a) {
        cout << "[Subscriber Created]" << endl;
    }

    void readArticle() const {
        if (article)
            article->read();
        else
            cout << "No article to read." << endl;
    }

    ~Subscriber() {
        cout << "[Subscriber Deleted]" << endl;
    }
};

int main() {
    shared_ptr<Article> article = make_shared<Article>("Breaking News: C++ Rocks!");

    {
        Subscriber s1(article);
        Subscriber s2(article);
        Subscriber s3(article);

        s1.readArticle();
        s2.readArticle();
        s3.readArticle();

        cout << "Use count (shared_ptr): " << article.use_count() << endl;
    }

    // All subscribers out of scope; article should be deleted
    cout << "After all subscribers are gone..." << endl;
    cout << "Use count (shared_ptr): " << article.use_count() << endl;

    return 0;
}
```

---

### 🧪 Output:

```
[Article Created]: Breaking News: C++ Rocks!
[Subscriber Created]
[Subscriber Created]
[Subscriber Created]
Reading Article: Breaking News: C++ Rocks!
Reading Article: Breaking News: C++ Rocks!
Reading Article: Breaking News: C++ Rocks!
Use count (shared_ptr): 4
[Subscriber Deleted]
[Subscriber Deleted]
[Subscriber Deleted]
[Article Deleted]: Breaking News: C++ Rocks!
After all subscribers are gone...
Use count (shared_ptr): 1
```

---

### 🔍 Key Concepts Illustrated

| Concept            | Description                                                   |
| ------------------ | ------------------------------------------------------------- |
| `make_shared`      | Efficient and exception-safe way to create `shared_ptr`       |
| Shared ownership   | `Subscriber` objects share ownership of the same `Article`    |
| Reference counting | Automatically deletes `Article` when all owners are destroyed |
| RAII               | Resource is cleaned up when no longer needed                  |
| Real-world mapping | Simulates a broadcast/readership model                        |

---
