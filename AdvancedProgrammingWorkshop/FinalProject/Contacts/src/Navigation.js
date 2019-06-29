import {
  createAppContainer,
  createStackNavigator,
} from 'react-navigation'
import Home from './screens/Home'
import NewContact from './screens/NewContact'
import About from './screens/About'

const MainNav = createStackNavigator(
  {
    Home,
    NewContact,
    About,
  }, {
    headerMode: 'none'
  }
)

export default createAppContainer(MainNav)
