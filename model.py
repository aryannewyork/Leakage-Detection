from sklearn.cluster import KMeans
import numpy as np
import pandas as pd
from sklearn.preprocessing import MinMaxScaler
from matplotlib import pyplot as plt

# %matplotlib inline

df = pd.read_excel("Book1.xlsx")
df.head()


plt.scatter(df.Time, df["Reading"])
plt.xlabel("Time")
plt.ylabel("Vibration(magnitude)")
plt.show()

# km = KMeans(n_clusters=2)


df["Time"] = abs(np.fft.fft(df["Reading"]))

scaler = MinMaxScaler()

scaler.fit(df[["Reading"]])
df["Reading"] = scaler.transform(df[["Reading"]])

scaler.fit(df[["Time"]])
df["Time"] = scaler.transform(df[["Time"]])
df.head()

plt.scatter(df.Time, df["Reading"])
plt.xlabel("Frequency")
plt.ylabel("Vibration(magnitude)")
plt.show()

km = KMeans(n_clusters=2)
y_predicted = km.fit_predict(df[["Time", "Reading"]])
print(y_predicted)
df["cluster"] = y_predicted
df.head()


df1 = df[df.cluster == 0]
df2 = df[df.cluster == 1]
plt.scatter(df1.Time, df1["Reading"], color="green")
plt.scatter(df2.Time, df2["Reading"], color="red")
plt.scatter(
    km.cluster_centers_[:, 0],
    km.cluster_centers_[:, 1],
    color="purple",
    marker="*",
    label="centroid",
)
plt.legend()
plt.xlabel("Frequency")
plt.ylabel("Vibration(magnitude)")
plt.show()
