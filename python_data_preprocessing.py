#importing libraries
import pandas as pd
import numpy as np
import warnings
warnings.filterwarnings("ignore")
from datetime import datetime

#Reading excel into fataframe named df
df = pd.read_csv('data_csv.csv')
df.head()


df.plot(grid = True);


df['hour'] = pd.to_datetime(df['time']).dt.hour
df['min'] = pd.to_datetime(df['time']).dt.minute
df['sec'] = pd.to_datetime(df['time']).dt.second
df.drop('time',axis = 1, inplace = True)
#Changing column positions
df = df[['hour','min','sec','value']]