import React, { Component } from 'react';
import {
  StyleSheet, View, TouchableNativeFeedback,
} from 'react-native';
import PropTypes from 'prop-types';
import Icon from './Icon';
import CustomText from './CustomText';
import Colors from '../common/Colors';


const styles = StyleSheet.create({
  container: {
    flexDirection: 'row',
    minWidth: 64,
    height: 36,
    paddingRight: 8,
    justifyContent: 'center',
    alignItems: 'center',
    elevation: 0,
  },
  icon: {
    paddingRight: 8,
  },
  label: {
    fontSize: 14,
    color: Colors.secondary,
  },
});


export default class TextButton extends Component {
  static propTypes = {
    label: PropTypes.string.isRequired,
    onPress: PropTypes.func.isRequired,
    icon: PropTypes.string,
    fill: PropTypes.bool,
    containerStyle: PropTypes.object,
  }

  static defaultProps = {
    icon: null,
    fill: false,
    containerStyle: null,
  }

  capitalize = text => text.toUpperCase()

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
      containerStyle,
      label,
      isRTL,
    } = this.props;

    return (
      <View style={fill ? {} : { flexDirection: 'row' }}>
        <TouchableNativeFeedback onPress={onPress}>
          <View
            style={[
              styles.container,
              icon ? { paddingLeft: 6 } : { paddingLeft: 8 },
              containerStyle,
            ]}
          >
            {this.renderIcon(icon)}
            <CustomText style={styles.label} isRTL>{label}</CustomText>
          </View>
        </TouchableNativeFeedback>
      </View>
    );
  }
}
