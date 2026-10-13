
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.tree import DecisionTreeClassifier, plot_tree
from sklearn.preprocessing import LabelEncoder
from sklearn.model_selection import train_test_split

df = pd.read_csv("file.csv")

X = df["data1"].copy()
y = df["data2"].copy()

le1 = LabelEncoder()
X = le1.fit_transform(X.astype(str))
X = X.reshape(-1, 1)

le2 = LabelEncoder()
y = le2.fit_transform(y.astype(str))

X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.2, random_state=42
)

clf = DecisionTreeClassifier(
    criterion="entropy",
    max_depth=3,
    random_state=42
)

clf.fit(X_train, y_train)

print("ID3 Accuracy:", clf.score(X_test, y_test))

plt.figure(figsize=(10, 6))
plot_tree(
    clf,
    feature_names=["data1"],
    class_names=le2.classes_,
    filled=True
)
plt.title("ID3 Tree")
plt.show()
