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
    paddingRight: 16,
    justifyContent: 'center',
    alignItems: 'center',
    elevation: 2,
    borderRadius: 4,
    backgroundColor: Colors.secondary,
  },
  icon: {
    paddingRight: 8,
  },
  label: {
    fontSize: 14,
    color: Colors.onSecondary,
  },
});


export default class ContainedButton extends Component {
  static propTypes = {
    label: PropTypes.string.isRequired,
    onPress: PropTypes.func.isRequired,
    icon: PropTypes.string,
    fill: PropTypes.bool,
    containerStyle: PropTypes.object,
    textStyle: PropTypes.object,
    disabled: PropTypes.bool,
  }

  static defaultProps = {
    icon: null,
    fill: false,
    containerStyle: null,
    textStyle: null,
    disabled: false,
  }

  renderIcon = (icon, disabled = false) => {
    if (icon) {
      return (
        <Icon
          name={icon}
          size={18}
          color={disabled ? '#888888' : Colors.onSecondary}
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
      textStyle,
      disabled,
    } = this.props;

    return (
      <View style={fill ? {} : { flexDirection: 'row' }}>
        {disabled
          ? (
            <View
              style={[
                styles.container,
                icon ? { paddingLeft: 12 } : { paddingLeft: 16 },
                containerStyle,
                { backgroundColor: '#ccc' },
              ]}
            >
              {this.renderIcon(icon, true)}
              <CustomText
                style={[
                  styles.label,
                  textStyle,
                  { color: '#888888' },
                ]}
              >
                {label}
              </CustomText>
            </View>
          )
          : (
            <TouchableNativeFeedback onPress={onPress}>
              <View
                style={[
                  styles.container,
                  icon ? { paddingLeft: 12 } : { paddingLeft: 16 },
                  containerStyle,
                ]}
              >
                {this.renderIcon(icon)}
                <CustomText style={[styles.label, textStyle]}>{label}</CustomText>
              </View>
            </TouchableNativeFeedback>
          )
        }
      </View>
    );
  }
}
