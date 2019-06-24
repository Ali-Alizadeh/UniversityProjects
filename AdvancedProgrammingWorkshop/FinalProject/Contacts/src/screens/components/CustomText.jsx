import React from 'react';
import {
  StyleSheet, Text, I18nManager,
} from 'react-native';
import PropTypes from 'prop-types';


const styles = StyleSheet.create({
  text: {
    textAlign: 'auto',
  },
});

const CustomText = (props) => {
  const { style, children, isRTL } = props;

  return (
    <Text
      {...props}
      style={[
        styles.text,
        {
          fontFamily: I18nManager.isRTL || isRTL ? 'Shabnam-FD-WOL' : 'Roboto',
        },
        style,
      ]}
    >
      {children}
    </Text>
  );
};

CustomText.propTypes = {
  style: PropTypes.oneOfType([
    PropTypes.object,
    PropTypes.array,
  ]),
  children: PropTypes.oneOfType([
    PropTypes.string,
    PropTypes.array,
    PropTypes.object,
    PropTypes.number,
  ]).isRequired,
};

CustomText.defaultProps = {
  style: {},
};

export default CustomText;
