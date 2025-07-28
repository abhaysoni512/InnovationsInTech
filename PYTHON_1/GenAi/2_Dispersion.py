import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import seaborn 

series = pd.Series([2,3,5,8,9,11,23,43])

print(series.max())

print(series.describe())
print("--------------------------------")

print(f"variance : {series.var()}")

print("--------------------------------")

print("--------------1------------------")
series1 = pd.Series([10,30,60,60,30,10])
print(series1.describe())
print("--------------2------------------")
series2 = pd.Series([10,40,30,90,20,10])
print(series2.describe())