"use strict";(self.webpackChunk_N_E=self.webpackChunk_N_E||[]).push([[4683],{78182:function(e,n,t){var a=t(38303);Object.defineProperty(n,"j7",{enumerable:!0,get:function(){return a.AnalyticsActions}}),Object.defineProperty(n,"Cs",{enumerable:!0,get:function(){return a.MessageType}})},38303:function(e,n){Object.defineProperty(n,"__esModule",{value:!0}),n.MessageType=n.AnalyticsActions=void 0,function(e){e.CLONE="clone",e.DEL="del",e.SET="set",e.TRACK="track"}(n.AnalyticsActions||(n.AnalyticsActions={})),function(e){e.ANALYTICS="Analytics"}(n.MessageType||(n.MessageType={}))},48496:function(e,n,t){t.d(n,{Y:function(){return u}});var a=t(93750),r=t(52645),o=t(77671),s=t(71732),i=t(67294),l=t(91792),c=t(17985);t(91829);var d={banner:"alert-banner-styles__banner___1GEzr","info-banner":"alert-banner-styles__info-banner___2IkKv","error-banner":"alert-banner-styles__error-banner___291Lk","neutral-banner":"alert-banner-styles__neutral-banner___2nayQ","success-banner":"alert-banner-styles__success-banner___3gKQ2"};const u=({children:e,cta:n,isDismissible:t,variant:a,ariaDismissLabel:r,ariaIconLabel:o,onClose:s,onAction:l})=>i.createElement(f,{variant:a},i.createElement(p,{variant:a,ariaIconLabel:o}),i.createElement(v,{cta:n,onAction:l},e),t&&i.createElement(m,{ariaDismissLabel:r,onClose:s})),f=({children:e,variant:n})=>{const t={[l.k.ERROR]:"error-banner",[l.k.INFO]:"info-banner",[l.k.SUCCESS]:"success-banner",[l.k.NEUTRAL]:"neutral-banner"};return i.createElement(c.Flex,{alignContent:"stretch"},i.createElement(c.View,{paddingEnd:"size-100",paddingStart:"size-275",paddingY:{base:"size-200",L:"size-100"},width:"100%",UNSAFE_className:d.banner+" "+d[t[n]],"data-testid":"pandora-react-alert-banner"},i.createElement(c.Flex,{gap:"size-150",alignItems:"stretch"},e)))},E=({children:e})=>i.createElement(c.View,{flexGrow:1,marginTop:"size-65",paddingEnd:"size-175"},i.createElement("span",{"data-testid":"pandora-react-alert-banner-message","aria-live":"polite"},e)),b=({cta:e,onAction:n})=>e?i.createElement(c.Button,{variant:"secondary",onPress:n,flexShrink:0,top:"1px",staticColor:"white"},e):null,v=({children:e,cta:n,onAction:t})=>i.createElement(c.Flex,{flexGrow:1,wrap:!0,gap:"size-100",justifyContent:"end"},i.createElement(E,null,e),i.createElement(b,{cta:n,onAction:t})),m=({ariaDismissLabel:e,onClose:n})=>i.createElement(c.Flex,null,i.createElement(c.Divider,{orientation:"vertical",size:"S",UNSAFE_style:{opacity:.3}}),i.createElement(c.ActionButton,{isQuiet:!0,onPress:n,height:"size-400",minWidth:"size-400",marginStart:"size-100",staticColor:"white"},i.createElement(r.default,{"aria-label":e,size:"S"}))),p=({variant:e,ariaIconLabel:n})=>e===l.k.NEUTRAL?null:i.createElement(c.View,null,e===l.k.ERROR&&i.createElement(a.Z,{"aria-label":n,size:"S",marginTop:"size-85"}),e===l.k.INFO&&i.createElement(o.Z,{"aria-label":n,size:"S",marginTop:"size-85"}),e===l.k.SUCCESS&&i.createElement(s.Z,{"aria-label":n,size:"S",marginTop:"size-85"}))},91792:function(e,n,t){var a;t.d(n,{k:function(){return a}}),function(e){e.ERROR="error",e.INFO="info",e.SUCCESS="success",e.NEUTRAL="neutral"}(a||(a={}))},69757:function(e,n,t){t.d(n,{o:function(){return v}});var a=t(817),r=t(78182);const{CLONE:o,DEL:s,SET:i,TRACK:l}=r.j7;class c{constructor(e){this.appName=e.appName,this.onEmitMessage=e.onEmitMessage,this.queuedEvents=[],this.sandboxUrl=e.sandboxUrl,e.sandboxRef&&(f(e),this.sandboxRef=e.sandboxRef)}setRef(e){f(Object.assign(Object.assign({},this),{sandboxRef:e}));for(const n of this.queuedEvents)e.contentWindow.postMessage(n,this.sandboxUrl);this.sandboxRef=e,this.queuedEvents=[]}track(e,n){u(this,d(this,{data:{data:n,tag:e},subType:l}))}set(e,n,t){u(this,d(this,{data:{key:e,snapshot:t,value:n},subType:i}))}del(e){u(this,d(this,{data:{key:e},subType:s}))}clone(){u(this,d(this,{subType:o}))}}function d(e,n){return Object.assign({app:e.appName,type:r.Cs.ANALYTICS},n)}function u(e,n){var t,a;e.sandboxUrl&&((null===(t=e.sandboxRef)||void 0===t?void 0:t.contentWindow)?e.sandboxRef.contentWindow.postMessage(n,e.sandboxUrl):e.queuedEvents.push(n)),null===(a=e.onEmitMessage)||void 0===a||a.call(e,n)}function f(e){if(!e.sandboxUrl)throw new Error("Rejected sandboxRef since sandboxUrl is undefined");if(!e.sandboxRef.contentWindow)throw new Error("Invalid sandboxRef for TrackingSandboxVendor")}var E=t(67294),b=t(57873);const v=e=>{const{children:n,isAnalyticsEmitted:t=!0,trackingSandboxUrl:o}=e,{vendor:s,onSandboxLoaded:i,onSandboxRefChanged:l}=function(e){const{appName:n,isAnalyticsEmitted:t=!0,trackingSandboxUrl:a}=e,[o,s]=(0,E.useState)(null),[i,l]=(0,E.useState)(!1),{emitMessage:d}=(0,b.UD)(),u=(0,E.useCallback)((e=>{t&&d(r.Cs.ANALYTICS,e)}),[d,t]),f=(0,E.useRef)(new c({appName:n,onEmitMessage:u,sandboxUrl:a}));return(0,E.useEffect)((()=>{f.current.onEmitMessage=u}),[t,u]),(0,E.useEffect)((()=>{f.current.sandboxUrl=a}),[a]),{onSandboxLoaded:()=>{l(!0),f.current.setRef(o)},onSandboxRefChanged:e=>{s(e),i&&(null===e||void 0===e?void 0:e.contentWindow)&&f.current.setRef(e)},vendor:f.current}}(e),d=o||t;return d&&"undefined"!==typeof window&&"undefined"===typeof window.digitalData&&(window.digitalData={}),E.createElement(E.Fragment,null,o&&E.createElement("iframe",{hidden:!0,onLoad:i,ref:l,src:o,title:"Analytics tracking sandbox"}),d?E.createElement(a.n,{value:s},n):E.createElement(E.Fragment,null,n))}},3490:function(e,n,t){var a;t.d(n,{vM:function(){return b},jK:function(){return E}}),function(e){e.CLIENT_ERROR="CLIENT_ERROR",e.SERVER_ERROR="SERVER_ERROR",e.ERROR=":error"}(a||(a={}));var r=t(11367),o=t(86706),s=t(47823),i=t(67294),l=t(74286);const c=()=>!0,d="setError",u="dismissError",f={[d]:(e,n)=>{const{payload:t}=n;return{error:t}},[u]:()=>({error:void 0})},E=(e=c,n="__APP_ERROR__")=>{const t=(0,i.useCallback)((e=>e[n]||{error:void 0}),[n]),{error:a}=(0,o.useSelector)(t);return a&&e(a)?a:void 0},b=(e="__APP_ERROR__")=>{const n=(0,i.useMemo)((()=>({error:void 0})),[]),{dispatch:t}=(0,s.m)(e,f,n),o=(0,l.K)();return(0,i.useMemo)((()=>({setError:(e,n=!0)=>{var s,i,l,c;if(n){const n=(new Date).toISOString(),t=(null===(s=null===e||void 0===e?void 0:e.extensions)||void 0===s?void 0:s.errorSource)===r.z.SERVER?"serverSideError":"clientSideError",d={eventName:`${(null===(i=e.extensions)||void 0===i?void 0:i.analyticsErrorMessage)||e.code}${a.ERROR}`,eventAction:t,timeStamp:n,start:n,end:n},u={[(null===(l=null===e||void 0===e?void 0:e.extensions)||void 0===l?void 0:l.errorSource)===r.z.SERVER?"server":"client"]:{primary:{errorInfo:{errorMessage:`${(null===(c=e.extensions)||void 0===c?void 0:c.analyticsErrorMessage)||e.code}${a.ERROR}`}}}};o({primaryEvent:{eventInfo:d},event:[{eventInfo:d}],error:{errorInfo:u}})}const u={message:e.message,type:e.type,code:e.code,extensions:e.extensions};t({type:d,payload:u})},dismissError:()=>{t({type:u})}})),[t,o])}},36458:function(e,n,t){var a=t(64836);n.Z=function(e){return s.default.createElement(o.Icon,e,s.default.createElement(r.A4uChevronLeft,null))};var r=t(99851),o=t(91769),s=a(t(67294))},77671:function(e,n,t){var a=t(64836);n.Z=function(e){return s.default.createElement(o.Icon,e,s.default.createElement(r.A4uInfo,null))};var r=t(53960),o=t(91769),s=a(t(67294))},99851:function(e,n,t){Object.defineProperty(n,"__esModule",{value:!0}),n.A4uChevronLeft=function(e){var n=o({},e);return r.default.createElement("svg",o({viewBox:"0 0 36 36"},n,n),r.default.createElement("path",{fillRule:"evenodd",d:"M12,18v0a1.988,1.988,0,0,0,.585,1.409l7.983,7.98a2,2,0,1,0,2.871-2.772l-.049-.049L16.819,18l6.572-6.57a2,2,0,0,0-2.773-2.87l-.049.049-7.983,7.98A1.988,1.988,0,0,0,12,18Z"}))};var a,r=(a=t(67294))&&a.__esModule?a:{default:a};function o(){return(o=Object.assign?Object.assign.bind():function(e){for(var n=1;n<arguments.length;n++){var t=arguments[n];for(var a in t)Object.prototype.hasOwnProperty.call(t,a)&&(e[a]=t[a])}return e}).apply(this,arguments)}},53960:function(e,n,t){Object.defineProperty(n,"__esModule",{value:!0}),n.A4uInfo=function(e){var n=o({},e);return r.default.createElement("svg",o({viewBox:"0 0 36 36"},n,n),r.default.createElement("path",{fillRule:"evenodd",d:"M18,2A16,16,0,1,0,34,18,16,16,0,0,0,18,2Zm-.3,4.3a2.718,2.718,0,0,1,2.864,2.824A2.664,2.664,0,0,1,17.7,11.987a2.705,2.705,0,0,1-2.864-2.864A2.717,2.717,0,0,1,17.7,6.3ZM22,27a1,1,0,0,1-1,1H15a1,1,0,0,1-1-1V25a1,1,0,0,1,1-1h1V18H15a1,1,0,0,1-1-1V15a1,1,0,0,1,1-1h4a1,1,0,0,1,1,1v9h1a1,1,0,0,1,1,1Z"}))};var a,r=(a=t(67294))&&a.__esModule?a:{default:a};function o(){return(o=Object.assign?Object.assign.bind():function(e){for(var n=1;n<arguments.length;n++){var t=arguments[n];for(var a in t)Object.prototype.hasOwnProperty.call(t,a)&&(e[a]=t[a])}return e}).apply(this,arguments)}}}]);