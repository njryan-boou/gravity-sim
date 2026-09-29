import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv("data/field.csv")

x = df["x"]
y = df["y"]
gx = df["gx"]
gy = df["gy"]

magnitude = (gx**2 + gy**2)**0.5

gx_norm = gx / magnitude
gy_norm = gy / magnitude

plt.quiver(x, y, gx_norm, gy_norm)

plt.xlabel("x")
plt.ylabel("y")
plt.axis("equal")
plt.show()

plt.scatter(x, y, c=magnitude)
plt.colorbar(label="Gravitational field strength")
plt.axis("equal")
plt.show()