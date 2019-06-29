import React, { Component } from 'react';
import {
  StyleSheet, View, TextInput, Animated, Easing,
} from 'react-native';
import CustomText from './CustomText';
import Colors from '../common/Colors';


const styles = StyleSheet.create({
  input: {
    backgroundColor: '#f5f5f5',
    paddingTop: 16,
    paddingBottom: 16,
    paddingRight: 12,
    paddingLeft: 12,
    fontSize: 16,
    color: '#000000de',
    elevation: 0,
    borderTopRightRadius: 4,
    borderTopLeftRadius: 4,
    borderBottomWidth: 1,
    borderBottomColor: 'rgba(0,0,0,.2)',
  },
});


const Input = (props) => {
  const {
    style, onChangeText, defaultValue, autoCapitalize, keyboardType, autoCorrect, spellCheck, placeholder,
  } = props;

  return (
    <View style={style}>
      <TextInput
        style={styles.input}
        selectionColor={Colors.secondary}
        onChangeText={onChangeText}
        keyboardType={keyboardType}
        autoCapitalize={autoCapitalize}
        autoCorrect={autoCorrect}
        spellCheck={spellCheck}
        defaultValue={defaultValue}
        placeholder={placeholder}
      />
    </View>
  );
}

export default Input
