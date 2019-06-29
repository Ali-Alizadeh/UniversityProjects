import React from 'react';
import { StyleSheet, Text, View, Image, Dimensions } from 'react-native';
import Colors from '../common/Colors';

const emptyListImage = require('../assets/images/empty_list.jpg');

const { height } = Dimensions.get('screen');

const styles = StyleSheet.create({
  listEmptyContainer: {
    backgroundColor: Colors.background,
    justifyContent: 'center',
    alignItems: 'center',
    flex: 1,
    marginBottom: height / 10,
  },
  listEmptyImage: {
    width: 400,
    height: 300,
  },
});

const EmptyList = ({ text }) => (
  <View style={styles.listEmptyContainer}>
    <View style={{ alignItems: 'center' }}>
      <Image
        source={emptyListImage}
        style={styles.listEmptyImage}
      />
      <Text
        style={{
          fontSize: 16,
          letterSpacing: 0.5,
          lineHeight: 24,
          textAlign: 'center',
          paddingRight: 64,
          paddingLeft: 64,
          position: 'absolute',
          top: height / 2.65,
        }}
      >
        {text}
      </Text>
    </View>
  </View>
)

export default EmptyList;
