import React, { Component } from 'react';
import {
  StyleSheet, View, TouchableNativeFeedback,
} from 'react-native';
import PropTypes from 'prop-types';
import CustomText from './CustomText';
import Icon from './Icon';
import Colors from '../common/Colors';


const styles = StyleSheet.create({
  container: {
    flexDirection: 'row',
    minWidth: 64,
    height: 36,
    paddingRight: 16,
    justifyContent: 'center',
    alignItems: 'center',
    elevation: 0,
    borderRadius: 4,
    borderColor: '#0000001e',
    borderWidth: 1,
  },
  icon: {
    paddingRight: 8,
  },
  label: {
    fontSize: 14,
    color: Colors.secondary,
  },
});


export default class OutlinedButton extends Component {
  static propTypes = {
    label: PropTypes.string.isRequired,
    onPress: PropTypes.func.isRequired,
    icon: PropTypes.string,
    fill: PropTypes.bool,
  }

  static defaultProps = {
    icon: null,
    fill: false,
  }

  capitalize = text => text.toUpperCase();

  renderIcon = (icon) => {
    if (icon) {
      return (
        <Icon
          name={icon}
          size={18}
          color={Colors.secondary}
          style={styles.icon}
        />
      );
    }
    return null;
  }

  render() {
    const {
      fill,
      onPress,
      icon,
      label,
    } = this.props;

    return (
      <View style={fill ? {} : { flexDirection: 'row' }}>
        <TouchableNativeFeedback onPress={onPress}>
          <View style={[styles.container, icon ? { paddingLeft: 12 } : { paddingLeft: 16 }]}>
            {this.renderIcon(icon)}
            <CustomText style={styles.label}>{this.capitalize(label)}</CustomText>
          </View>
        </TouchableNativeFeedback>
      </View>
    );
  }
}
