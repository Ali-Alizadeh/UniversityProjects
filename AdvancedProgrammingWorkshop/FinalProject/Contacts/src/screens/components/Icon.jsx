import React, { Component } from 'react';
import {
  StyleSheet, TouchableNativeFeedback, View,
} from 'react-native';
import PropTypes from 'prop-types';
import Icons from 'react-native-vector-icons/MaterialIcons';


const styles = StyleSheet.create({
  icon: {
    // color: this.props.color,
    // padding: 12
  },
  iconWrapper: {
    width: 48,
    height: 48,
    alignItems: 'center',
    justifyContent: 'center',
  },
});


export default class Icon extends Component {
  static propTypes = {
    name: PropTypes.string.isRequired,
    color: PropTypes.string,
    rippleColor: PropTypes.string,
    onPress: PropTypes.func,
    size: PropTypes.number,
    style: PropTypes.object,
    ripple: PropTypes.bool,
  }

  static defaultProps = {
    rippleColor: 'rgba(255, 255, 255, 0.6)',
    onPress: () => { },
    size: 24,
    color: '#000',
    style: {},
    ripple: false,
  }

  generateIcon = (isRipple) => {
    const {
      rippleColor, onPress, name, size, color,
    } = this.props;

    if (isRipple === true) {
      return (
        <TouchableNativeFeedback
          background={TouchableNativeFeedback.Ripple(rippleColor, true)}
          onPress={onPress}
        >
          <View style={styles.iconWrapper}>
            <Icons
              name={name}
              size={size}
              style={[styles.icon, { color }]}
            />
          </View>
        </TouchableNativeFeedback>
      );
    }
    return (
      <Icons
        name={name}
        size={size}
        style={[styles.icon, { color }]}
      />
    );
  }

  render() {
    const { style, ripple } = this.props;
    return (
      <View style={style}>
        {this.generateIcon(ripple)}
      </View>
    );
  }
}
