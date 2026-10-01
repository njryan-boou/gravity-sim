import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

df = pd.read_csv("data/field.csv")

gx_grid = df.pivot(index="y", columns="x", values="gx")
gy_grid = df.pivot(index="y", columns="x", values="gy")
potential_grid = df.pivot(index="y", columns="x", values="potential")

X, Y = np.meshgrid(
    gx_grid.columns.to_numpy(),
    gx_grid.index.to_numpy()
)

GX = gx_grid.to_numpy()
GY = gy_grid.to_numpy()
PHI = potential_grid.to_numpy()

magnitude = np.sqrt(GX**2 + GY**2)

GX_norm = GX / magnitude
GY_norm = GY / magnitude

plt.contour(X, Y, PHI, levels=20)
plt.quiver(X, Y, GX_norm, GY_norm)

plt.xlabel("x")
plt.ylabel("y")
plt.axis("equal")

plt.savefig(
    "data/gravity_field.png",
    dpi=300,
    bbox_inches="tight"
)

plt.show()