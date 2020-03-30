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


#Adding new features year, month and day
#Adding new features year, month and day
df['hour'] = pd.to_datetime(df['time']).dt.hour
df['min'] = pd.to_datetime(df['time']).dt.minute
df['sec'] = pd.to_datetime(df['time']).dt.second
df.drop('time',axis = 1, inplace = True)
#Changing column positions
df = df[['hour','min','sec','value']]

# Target are the values we want to predict
target = np.array(df['value'])


# Convert to numpy array
features = np.array(df)

# Using Skicit-learn to split data into training and testing sets
from sklearn.model_selection import train_test_split
# Split the data into training and testing sets
train_features, test_features, train_labels, test_labels = train_test_split(features, target, test_size = 0.25,random_state = 42)

print('Training Features Shape:', train_features.shape)
print('Training Labels Shape:', train_labels.shape)
print('Testing Features Shape:', test_features.shape)
print('Testing Labels Shape:', test_labels.shape)


# Import the model we are using
from sklearn import tree
rf = tree.DecisionTreeClassifier()
# Train the model on training data
rf.fit(train_features, train_labels);

# Use the forest's predict method on the test data
predictions = rf.predict(test_features)
# Calculate the absolute errors
errors = abs(predictions - test_labels)
# Print out the mean absolute error (mae)
print('Mean Absolute Error:', round(np.mean(errors), 2), 'degrees.')